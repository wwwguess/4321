// Room: /d/sanyen/sroad1.c

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
����һ������������̦��ʯ��ɽ·������·���ų��������ߣ���
�˵�Ҳ����ʪ����������һ��ʯ�׻�����ɽ����������ͨ��ɽ�е�ɽ·
�������ɽ���Ͽ�����ɽ���¡��������֣������������Ѿ��ľ��ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
//  "north" : "/d/sanyen/sroad2",
  "west" : "/d/sanyen/sroad2",
"northdown" : "/u/cloud/sunhill/road4",
//  "southdown" : "/d/snow/eroad3",
]));
	set("outdoors", "sanyen");

	setup();
	replace_program(ROOM);
}
