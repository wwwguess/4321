// Room: /d/goathill/canyon3.c

inherit ROOM;

void create()
{
	set("short", "Ͽ��");
	set("long", @LONG
������������һ��Ͽ�ȵĹȵף�������ͱ�б��֮�����㵨���ľ�
��ֻ������������һ����Ƚ��������ʯ����������ֻ�����̾͵ñ���
�񣬶��ߵ��ͱ�����һ��������Ķ�Ѩ�������ƺ���ʲô�����������
��Ͽ�������Ϻ��������߸�����խ�ĳ��ڡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"east" : __DIR__"cavern1",
		"southwest" : __DIR__"canyon2",
]));

	setup();
	replace_program(ROOM);
}
