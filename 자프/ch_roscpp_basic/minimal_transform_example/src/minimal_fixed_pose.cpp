#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "tf2_geometry_msgs/tf2_geometry_msgs.hpp"

class MinimalFixedPose : public rclcpp::Node {
public:
    MinimalFixedPose() : Node("minimal_fixed_pose") {
        publisher_ = this->create_publisher<geometry_msgs::msg::PoseStamped>("fixed_pose", 10);
        timer_ = this->create_wall_timer(std::chrono::milliseconds(100),
            std::bind(&MinimalFixedPose::publish_pose, this));
        this->declare_parameter<double>("init_x", 1.0);
        this->declare_parameter<double>("init_y", 1.0);
        this->declare_parameter<std::string>("target_frame", "world");
        init_x_ = this->get_parameter("init_x").as_double();
        init_y_ = this->get_parameter("init_y").as_double();
        target_frame_ = this->get_parameter("target_frame").as_string();
    }

private:
    void publish_pose() {
        geometry_msgs::msg::PoseStamped pose_msg;
        pose_msg.header.stamp = this->now();
        pose_msg.header.frame_id = target_frame_;

        pose_msg.pose.position.x = init_x_;
        pose_msg.pose.position.y = init_y_;
        pose_msg.pose.position.z = 0.0;
        
        tf2::Quaternion q;
        q.setRPY(0, 0, -M_PI_2);  // Yaw = -π/2 (90 degrees) around Z-axis
        pose_msg.pose.orientation = tf2::toMsg(q);

        publisher_->publish(pose_msg);
    }
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr publisher_;
    std::string target_frame_;
    double init_x_;
    double init_y_;
};

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<MinimalFixedPose>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
