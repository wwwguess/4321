// Room: /city/nandajie1.c
// YZC 1995/12/04 

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", RED "�ϴ��" NOR);
	set("long", @LONG
	�ϴ�����ǳ���ķ����ضΣ�һ�����ϣ�һ�ɵƺ���̣���Ϊ���֡�Ц����
���������������������һƬ��������Ķ��䣬�㲻����Գ��������ʹ�ͣ������
һ����������һ�����ֵĹ㳡��������һ�ҵ��̣�ǽ��д��һ�����ġ������֣���
ϸ��������������ѹ�͵��ּۻ��۵���������������һƬ�����������š�һ��һʮ��
����Ǯ����ԭ�����Ƿ�Բǧ��֮������һ�Ҷĳ���
LONG
	);
        set("outdoors", "city");

	set("exits", ([
		"east" : __DIR__"dangpu",
		"south" : __DIR__"nanmen",
		"north" : __DIR__"guangchang",
	]));

        set("objects", ([
               "/class/shaolin/tuoboseng" : 1,
        ]));

	setup();
	replace_program(ROOM);
}

