
inherit ROOM;

void create()
{
    set("short", "��¥����");
	set("long", @LONG
�����ں�����¥�������ϣ�ׯ�������������Ⱥܶ࣬����û�е�
������������·���������ߵ���, �������ɵĳ��Ƽ��Ϲ���һ����
���Ĺ���! ��ҹ֮��ƻ�Ի�! ʮ������!
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
    "east" :__DIR__"upstar4",
    "south" :__DIR__"upcenter",
    "northdown" : "/d/latemoon/room/lroad3",

]));

	setup();
	replace_program(ROOM);
}
