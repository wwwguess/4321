
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
    "south" :__DIR__"eroad2",
    "west" :__DIR__"lcenter",

]));

	setup();
	replace_program(ROOM);
}
