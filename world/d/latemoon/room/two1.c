
inherit ROOM;

void create()
{
   set("short", "�е�");
	set("long", @LONG
�����ں�����Ժ�ļе��ϣ�ׯ�������������Ⱥܶ࣬����û�е�
������������·���������ߵ���, �������ɵĳ��Ƽ��Ϲ���һ����
���Ĺ���! ��ҹ֮��ƻ�Ի�! ʮ������!
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
    "south" :__DIR__"guest1",
    "east" :__DIR__"twoc",
    "west" :__DIR__"two2",

]));

	setup();
	replace_program(ROOM);
}
