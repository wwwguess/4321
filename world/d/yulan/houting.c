#include <room.h>

inherit ROOM;

void create()
{
        set("short","玉兰山庄后大厅");
        set("long", @LONG
走进大厅，抬头迎面看见的是一面粉红绣金挂幔，东西两面各设著七张紫
檀雕案，案上一色青玉花瓶，瓶中插著粉红的处子桃花，紫檀雕案中间又
都挂著七尺来长的画轴，门边放着一个剑架，架子上放着一把宝剑，这大
厅中的富贵气派之中透著一股英气。

LONG
        );
        set("exits", ([ /* sizeof() == 2 */
                "north" :__DIR__"yulanc",
        ]));

        setup();
        replace_program(ROOM);
}
