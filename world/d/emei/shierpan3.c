// Room: /d/emei/shierpan3.c ������ ʮ����3

inherit ROOM;

void create()
{
	set("short", "ʮ����");
	set("long", @LONG
�������ٲ��Ϸ�һ��խխ��ɽ������Ȼ��ɡ�ʯ�������˹�
���һ�����ݡ����϶��˼���ľ׮�����ϴֳ���������Ϊ���֡�
�ٲ��ڽ��±��ڶ������ڲ�Զ��ɽ���»��һ����̶��
LONG
	);

	set("exits", ([
		"east" : __DIR__"shierpan2",
		"southup" : __DIR__"shierpan4",
	]));

	set("outdoors", "shaolin");
	setup();
	replace_program(ROOM);
}



