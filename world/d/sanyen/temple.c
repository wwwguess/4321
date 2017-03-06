// Room: /d/sanyen/temple.c

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "���۱���");
	set("long", @LONG
һ��ҫ�۵Ľ������Ϯ��, �㶨��һ��ԭ������һ�ɰ˳ߵ�����
�������, ����һ�����߸ߵ���̨��, ǰ������¯�����̻���Ʈ����
��������ɽ���¶������Ϻõ���ľ�����, �Ϸ��������ȳ����Ľ�
��, ��ֵ����, ���Ʋ���, �ڷ�����Ҳ��е��Ʋ��, ��᣺��ƺ���
��ͨ�������������������ˮ����
LONG
	);
	set("valid_startroom", 1);
    set("exits", ([ /* sizeof() == 3 */
		"south" : "/d/sanyen/road1",
		"west" : "/d/sanyen/inner_yard",
        "north" : "/d/sanyen/corridor",
	]));

	set("objects", ([
		CLASS_D("bonze") + "/master": 1
	]) );

	create_door("south", "����", "north", DOOR_CLOSED);

	setup();
	call_other("/obj/board/bonze_b", "???");

	replace_program(ROOM);
}
