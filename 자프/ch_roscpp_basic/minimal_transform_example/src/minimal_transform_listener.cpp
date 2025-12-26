#include "rclcpp/rclcpp.hpp"
#include "tf2_ros/buffer.h"
#include "tf2_ros/transform_listener.h"
#include "geometry_msgs/msg/transform_stamped.hpp"

class MinimalTransformListener : public rclcpp::Node {
public:
    MinimalTransformListener() : Node("minimal_transform_listener") { 
        timer_ = this->create_wall_timer(std::chrono::milliseconds(100),
            std::bind(&MinimalTransformListener::query_transform, this));
        tf_buffer_ = std::make_unique<tf2_ros::Buffer>(this->get_clock());
        tf_listener_ = std::make_shared<tf2_ros::TransformListener>(*tf_buffer_);
        this->declare_parameter<std::string>("parent_frame", "world");
        this->declare_parameter<std::string>("child_frame", "target_frame");
    }

private:
    void query_transform() {
        try {
            std::string parent_frame = this->get_parameter("parent_frame").as_string();
            std::string child_frame = this->get_parameter("child_frame").as_string();

            geometry_msgs::msg::TransformStamped t =
                tf_buffer_->lookupTransform(parent_frame, child_frame, tf2::TimePointZero);
            
            RCLCPP_INFO(this->get_logger(), "(tx, ty, tz, qx, qy, qz, qw) = (%f, %f, %f, %f, %f, %f, %f)",
                t.transform.translation.x, t.transform.translation.y, t.transform.translation.z,
                t.transform.rotation.x, t.transform.rotation.y, t.transform.rotation.z, 
                t.transform.rotation.w);
        }
        catch (const tf2::TransformException &ex) {
            RCLCPP_WARN(this->get_logger(), "TF error: %s", ex.what());
        }
    }
    std::shared_ptr<tf2_ros::TransformListener> tf_listener_{nullptr};
    std::unique_ptr<tf2_ros::Buffer> tf_buffer_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<MinimalTransformListener>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
