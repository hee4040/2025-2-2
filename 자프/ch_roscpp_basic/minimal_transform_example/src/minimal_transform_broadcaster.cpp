#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "tf2_ros/transform_broadcaster.h"
#include "geometry_msgs/msg/transform_stamped.hpp"

class MinimalTransformBroadcaster : public rclcpp::Node {
public:
    MinimalTransformBroadcaster() : Node("minimal_transform_broadcaster") {
        tf_broadcaster_ = std::make_shared<tf2_ros::TransformBroadcaster>(this);
        pose_subscription_ = this->create_subscription<geometry_msgs::msg::PoseStamped>("moving_pose", 10,
            std::bind(&MinimalTransformBroadcaster::pose_callback, this, std::placeholders::_1));

        this->declare_parameter<std::string>("parent_frame", "world");
        this->declare_parameter<std::string>("child_frame", "target_frame");
    }

private:
    void pose_callback(const geometry_msgs::msg::PoseStamped::SharedPtr msg) {
        geometry_msgs::msg::TransformStamped transform;

        std::string parent_frame = this->get_parameter("parent_frame").as_string();
        std::string child_frame = this->get_parameter("child_frame").as_string();

        transform.header.stamp = msg->header.stamp;
        transform.header.frame_id = parent_frame;
        transform.child_frame_id = child_frame;

        transform.transform.translation.x = msg->pose.position.x;
        transform.transform.translation.y = msg->pose.position.y;
        transform.transform.translation.z = msg->pose.position.z;
        transform.transform.rotation = msg->pose.orientation;

        tf_broadcaster_->sendTransform(transform);
    }
    std::shared_ptr<tf2_ros::TransformBroadcaster> tf_broadcaster_;
    rclcpp::Subscription<geometry_msgs::msg::PoseStamped>::SharedPtr pose_subscription_;
};

int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MinimalTransformBroadcaster>());
    rclcpp::shutdown();
    return 0;
}
