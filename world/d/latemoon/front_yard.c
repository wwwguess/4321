#include <room.h>

inherit ROOM;

void create()
{
	set("short", "����ׯǰͥ");
	set("long", @LONG
һ�������ͥ԰���˱Ƕ����ı���һ���������ޣ�������������
Ƣ�Ļ��㣬ͥ԰���ǿ�������滨��ʯ������䣬���Ǿ������ֽ�
�˵ľ��Ĳ��ã����߻��Լ�ɿ������ݵ��ݽǣ�һ��ʯ��С��������
ɽͨ�����ݡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"out" :__DIR__"gate",
		"west" :__DIR__"latemoon1",
        "south" :__DIR__"park/yard1",
	]));
    set("outdoors", "latemoon");

	setup();
	replace_program(ROOM);
}

