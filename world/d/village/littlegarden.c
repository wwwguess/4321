inherit ROOM;
#include <room.h>

void create()
{
        set("short", "��԰");
        set("long", @LONG
�������Ϻ���С��԰����԰���кܶ������Ļ��䡣���Ϻ�
���ǿ�������ά�����Ƶġ��������ǻ����Ĵ�ü��ڣ��кܶ�
���ڼ�����
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
        "south" : __DIR__"road5",
	"north" : __DIR__"home",
        ]));
        create_door("north", "ľ��", "south", DOOR_CLOSED);
	
	set("objects", ([
        __DIR__"npc/flowergirl" : 5,
        ]) );
        set("outdoors", "village");
        setup();
}
                
