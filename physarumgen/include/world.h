#pragma once

#include "agent.h"
#include "world_sampler.h"
#include <vector>
#include <opencv2/highgui.hpp>

class c_world
{
    public:
        c_world(unsigned int width, unsigned int height);
        bool spawn_agents(float world_percentage);
        void movement_step();
        void sensory_step();
        void update_world();
        void display(int delay) const;
    private:
        bool check_inbounds(unsigned int x, unsigned int y) const;
        std::vector<c_agent> m_agents;
        unsigned int m_width;
        unsigned int m_height;
        cv::Mat m_world_grid;
        cv::Mat m_trail_grid;
        c_world_sampler m_world_sampler;
};