//   
//  west_door
#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
        object san, sna;
        set("short","��������" );
        set("long", @LONG
����Ǵ����������,������ΰ׳��.�ſ�����
��������,���˲�������!û�µĻ�������㿪
��ĺ�.
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
 
