// Room: /d/emei/jietuopo.c ������ ������


inherit ROOM;




void create()
{
	set("short", "������");
	set("long", @LONG
�������ٲ��Ϸ�һ��խխ��ɽ������Ȼ��ɡ�ʯ�������˹�
���һ�����ݡ����϶��˼���ľ׮�����ϴֳ���������Ϊ���֡�
�ٲ��ڽ��±��ڶ������ڲ�Զ��ɽ���»��һ����̶��
LONG
	);

	set("exits", ([
		"east" : __DIR__"milin2",
		"west" : __DIR__"guanyitang",
	]));

	set("outdoors", "shaolin");
	setup();
	replace_program(ROOM);
}



