// Room: /d/ice/cave0.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
һ����խ��ɽ��, �����Ķ��ڱ�һЩ��֪����ֲ�����ס��һ���,
����Ĺ�����϶�����ս���, ���󺮷�Ҳ��֮����. ��������ˮ�ı���
���ڶ���, ˮ���ڵ����γ�һ�����İ���. ������һ��Լһ�˸ߵ�ͨ��
������Ĳ�֪ͨ���δ�.
 
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"east" : "/d/mine/cave0",
		"west" : __DIR__"path0",
]));

	setup();
	replace_program(ROOM);
}
