// Room: /d/goathill/canyon1.c

inherit ROOM;

void create()
{
	set("short", "Ͽ��");
	set("long", @LONG
������������һ��������Ͽ��֮�У��������߶��Ǹ߲����ʵ��ͱ�
��һ���塢���ɿ��ʯ�����������ͷ���Ĺȿڣ�������ҡҡ��׹����
һ������ֻ�µ����ͻᱻѹ��һ����������Ͼ���Ͽ�ȵĳ��ڣ�Ͽ�ȹ�
�׵ĵ��濴��������Ǭ�Ե�ɽ����������������ͨ��Ͽ�����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"northdown" : __DIR__"canyon2",
		"south" : __DIR__"mroad6",
]));

	setup();
	replace_program(ROOM);
}
