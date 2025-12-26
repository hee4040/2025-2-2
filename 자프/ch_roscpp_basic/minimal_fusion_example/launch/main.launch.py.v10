from launch import LaunchDescription
# from launch_ros.actions import Node

from launch_ros.actions import ComposableNodeContainer
from launch_ros.descriptions import ComposableNode

def generate_launch_description():
    return LaunchDescription([
        ComposableNodeContainer(
            name='minimal_fusion_example',
            namespace='',
            package='rclcpp_components',
            executable='component_container_mt', # use component_container for single-threaded executor
            composable_node_descriptions=[
                ComposableNode(
                    package='minimal_fusion_example',
                    plugin='MinimalPublisher',
                    name='talker_w_period_1s',
                    parameters=[
                        {"timer_period": 1000},
                        {"init_x": 1.0},
                        {"init_y": 0.0},
                    ],
                    remappings=[
                        ('topic', 'topic_1'),
                    ],
                    extra_arguments=[{'use_intra_process_comms': True}],
                ),
                ComposableNode(
                    package='minimal_fusion_example',
                    plugin='MinimalPublisher',
                    name='talker_w_period_2s',
                    parameters=[
                        {"timer_period": 2000},
                        {"init_x": 0.0},
                        {"init_y": 1.0},
                    ],
                    remappings=[
                        ('topic', 'topic_2'),
                    ],
                    extra_arguments=[{'use_intra_process_comms': True}],
                ),
                ComposableNode(
                    package='minimal_fusion_example',
                    plugin='MinimalFusion',
                    name='fusion_w_period_1s',
                    parameters=[
                        {"timer_period": 1000}
                    ],
                    extra_arguments=[{'use_intra_process_comms': True}],
                ),
            ]
        )
    ])