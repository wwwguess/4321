
inherit ROOM;

void create()
{
   set("short", "�����ߵ�");
	set("long", @LONG
�����ں�����Ժ�ļе��ϣ�ׯ�������������Ⱥܶ࣬����û�е�
������������·���������ߵ���, �������ɵĳ��Ƽ��Ϲ���һ����
���Ĺ���! ��ҹ֮��ƻ�Ի�! ʮ������!
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
    "east" :__DIR__"lcenter",
    "west" :__DIR__"room4",
    "south" :__DIR__"wroad1",
    "northup" : "/d/latemoon/upstar/upstar1",

]));

	setup();
	replace_program(ROOM);
}
