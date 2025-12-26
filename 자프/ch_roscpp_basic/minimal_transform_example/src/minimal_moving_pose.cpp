#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include <cmath>

class MinimalMovingPose : public rclcpp::Node {
public:
    MinimalMovingPose(): Node("minimal_moving_pose") {
        this->declare_parameter<double>("radius", 2.0);
        this->declare_parameter<double>("angular_velocity", 0.5);  // rad/s
        this->declare_parameter<std::string>("target_frame", "world");
        
        radius_ = this->get_parameter("radius").as_double();
        angular_velocity_ = this->get_parameter("angular_velocity").as_double();
        target_frame_ = this->get_parameter("target_frame").as_string();

        publisher_ = this->create_publisher<geometry_msgs::msg::PoseStamped>("moving_pose", 10);
        timer_ = this->create_wall_timer(std::chrono::milliseconds(100),
            std::bind(&MinimalMovingPose::publish_pose, this));
        start_time_ = this->get_clock()->now();
    }

private:
    geometry_msgs::msg::Quaternion create_quaternion_from_yaw(double yaw) {
        geometry_msgs::msg::Quaternion q;
        q.x = 0.0;
        q.y = 0.0;
        q.z = sin(yaw / 2);
        q.w = cos(yaw / 2);
        return q;
    }

    void publish_pose() {
        auto pose_msg = geometry_msgs::msg::PoseStamped();
        pose_msg.header.stamp = this->get_clock()->now();
        pose_msg.header.frame_id = target_frame_;

        auto current_time = this->get_clock()->now();
        double elapsed_seconds = (current_time - start_time_).seconds();
        double theta = angular_velocity_ * elapsed_seconds;

        pose_msg.pose.position.x = radius_ * cos(theta);
        pose_msg.pose.position.y = radius_ * sin(theta);
        pose_msg.pose.position.z = 0.0;

        double yaw = theta + M_PI_2;  // Add 90 degrees to face tangent direction
        pose_msg.pose.orientation = create_quaternion_from_yaw(yaw);
        publisher_->publish(pose_msg);
    }

    rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Time start_time_;
    double radius_;
    double angular_velocity_;
    std::string target_frame_;
};

int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MinimalMovingPose>());
    rclcpp::shutdown();
    return 0;
}
