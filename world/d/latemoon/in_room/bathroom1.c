#include <room.h>

inherit ROOM;

void create()
{
   set("short", "��ԡ������");
	set("long", @LONG
����һ������ң��㿴�������ӣ��¼��Ϲ��������·���
Ʒ��ǽ�ϵļ��Ϲ���һЩ˿��������ŵ�����������Χ�����ܡ�
����һ��������������������ȥ����Լ�ɿ���С���أ�һ�ŵ�����
���е���ȥ������ԡ���þ����Щ����Ȼ�˴��ǽ�ֹ���Խ���!
LONG
	);
    set("objects", ([

     "/d/latemoon/npc/shinyu" : 1 ]) );
	set("exits", ([ /* sizeof() == 2 */
     "west" :__DIR__"flower1",
     "east" :__DIR__"bathroom",

]));

    create_door("west","С����","east", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}
