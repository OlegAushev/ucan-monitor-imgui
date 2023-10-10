#pragma once


#include <imgui.h>
#include <implot.h>
#include <ucanopen/server/server.h>
#include <memory>


namespace ui {


class WatchCharts {
private:
    std::shared_ptr<::ucanopen::Server> _server;
public:
    WatchCharts(std::shared_ptr<::ucanopen::Server> server) : _server(server) {
        _init_charts();
    }
    void draw(bool& open);
private:
    void _draw_plot();
private:
    struct Chart {
        std::string_view subcategory;
        std::string_view name;
        std::string label;
        bool on_plot;
        const float* p_time;
        const float* p_value;
        ImAxis y_axis;

    };
    std::vector<Chart> _charts;

    void _init_charts() {
        for (const auto& obj : _server->watch_service.objects()) {
            Chart chart;
            chart.subcategory = obj->subcategory;
            chart.name = obj->name;
            chart.label = std::string(obj->subcategory) + "::" + std::string(obj->name);    
            chart.on_plot = false;            
            chart.p_time = &(_server->watch_service.history(chart.subcategory, chart.name)->array_two().first->x());
            chart.p_value = &(_server->watch_service.history(chart.subcategory, chart.name)->array_two().first->y());
            chart.y_axis = ImAxis_Y1;
            _charts.push_back(chart);
        }
    }
};


} // namespace ui
