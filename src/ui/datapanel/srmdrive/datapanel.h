#pragma once


#include <imgui.h>
#include "../interface.h"
#include <ucanopen_servers/srmdrive/srmdrive_server.h>
#include <memory>


namespace ui {
namespace srmdrive {

class DataPanel : public DataPanelInterface {
private:
    std::shared_ptr<::srmdrive::Server> _server;
public:
    DataPanel(std::shared_ptr<::srmdrive::Server> server) : _server(server) {}
    virtual void draw(bool& open) override;
private:
    void _draw_watch_table();
    void _draw_tpdo1_table();
    void _draw_tpdo2_table();
    void _draw_tpdo3_table();
    void _draw_tpdo4_table();
};


} // namespace srmdrive
} // namespace ui
