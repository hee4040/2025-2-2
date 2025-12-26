from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package="minimal_transform_example",
            executable="minimal_moving_pose",
            name="minimal_moving_pose",
            output="screen",
            emulate_tty=True,
            parameters=[
                {"radius": 2.0},
                {"angular_velocity": 0.5},
                {"target_frame": "world"},
            ],
        ),
        Node(
            package="minimal_transform_example",
            executable="minimal_fixed_pose",
            name="minimal_fixed_pose",
            output="screen",
            emulate_tty=True,
            parameters=[
                {"init_x": -2.0},
                {"init_y": 2.0},
                {"target_frame": "base_link"},
            ],
        ),
        Node(
            package="minimal_transform_example",
            executable="minimal_transform_broadcaster",
            name="minimal_transform_broadcaster",
            output="screen",
            emulate_tty=True,
            parameters=[
                {"parent_frame": "world"},
                {"child_frame": "base_link"},
            ],
        ),
        Node(
            package="minimal_transform_example",
            executable="minimal_transform_listener",
            name="minimal_transform_listener",
            output="screen",
            emulate_tty=True,
            parameters=[
                {"parent_frame": "world"},
                {"child_frame": "base_link"},
            ],
        ),
    ])