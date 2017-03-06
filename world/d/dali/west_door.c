//   
//  west_door
#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
        object san, sna;
        set("short","大理西门" );
        set("long", @LONG
这儿是大理国的西门,城门雄伟壮观.门口立着
几个卫兵,令人不寒而栗!没事的话还是早点开
溜的好.
LONG
        );
        set("exits", ([
  "east"  : __DIR__"dalicheng",
  "west" : __DIR__"road1",
]));                              

        set("outdoors", "dali");

        setup();replace_program(ROOM);

}

void init()
{
        return;
}                
 
