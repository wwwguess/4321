
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
    "south" :__DIR__"guest2",
    "east"  :__DIR__"two1",

]));

	setup();
	replace_program(ROOM);
}
