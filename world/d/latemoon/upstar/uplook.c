
#include <room.h>
inherit ROOM;

void create()
{
    set("short", "�۾�̨");
	set("long", @LONG
��������ׯ��ǰ��¥�۾�̨��վ��̨ǰ����Կ�������ׯԺ��  
���֣����ɽ������ɫ�������΢΢��ɽ�����������ӣ�����
˵��������ˬ��Զ��ɽ�µ���������������䣬����ǰ�ľ�ɫ����
һ��ɽ�ַ��ķ羰�������·���ǰԺ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
    "west" :__DIR__"upstarc",
    "jump" : "/d/latemoon/park/yard1",

]));

    set("objects", ([
        __DIR__"npc/bird" : 2,
    ]) );
    set("outdoors", "latemoon");
    create_door("west","¥��","east", DOOR_CLOSED);
    setup();
	replace_program(ROOM);
}
