// Room: /d/goathill/mroad3.c

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
������������һ����᫵�ɽ·�ϣ����ߵ�·��һ��ɽ�ڵ��ѷ�����
һ��С�������￴��ȥ��������ƺ�û�����չˣ�ɽ·������һ�ζ�
�͵����£������ϵ�ɽ·��ƽ���öࡣ
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		"northup" : __DIR__"mroad4",
		"east" : __DIR__"temple1",
		"southwest" : __DIR__"mroad2",
]));
	set("outdoors", "goathill");

	setup();
	replace_program(ROOM);
}
