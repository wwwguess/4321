inherit ROOM;
#include <room.h>
void create()
{
        set("short", "����С��");
        set("long", @LONG
����һ�����ƾɵ�ľ�ݡ�ÿ��ɽ�紵�������ᷢ����֨֨ѽѽ��
���������ϲ���һ��СС�ĳ�����ľ�ݵĺ�����һ�����ɵĻ�԰����
԰�ﴩ���������֮����һ�����̵�С��ƺ�������档
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
        "south" : __DIR__"smallstorage",
          "north" : __DIR__"littlegarden",
            "west" : __DIR__"smallyard",
              "southwest" : __DIR__"dustyroad3",
              ]));
              
              create_door("southwest", "ľ��", "northeast", DOOR_CLOSED);
              
              
              set("objects", ([
              __DIR__"npc/oldliu" : 1,
                      ]) );
                      
              setup();
}
