// Room: /d/emei/shierpan2.c ������ ʮ����2


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
		"northdown" : __DIR__"shierpan1",
		"west" : __DIR__"shierpan3",
	]));

	set("outdoors", "shaolin");
	setup();
	replace_program(ROOM);
}



