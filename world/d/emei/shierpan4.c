// Room: /d/emei/shierpan4.c ������ ʮ����4

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
		"northdown" : __DIR__"shierpan3",
		"westup" : __DIR__"huayanding",
	]));

	set("outdoors", "shaolin");
	setup();
	replace_program(ROOM);
}



