// Room: /d/emei/milin2.c ������ ����2


inherit ROOM;




void create()
{
	set("short", "����");
	set("long", @LONG
�������ٲ��Ϸ�һ��խխ��ɽ������Ȼ��ɡ�ʯ�������˹�
���һ�����ݡ����϶��˼���ľ׮�����ϴֳ���������Ϊ���֡�
�ٲ��ڽ��±��ڶ������ڲ�Զ��ɽ���»��һ����̶��
LONG
	);

	set("exits", ([
		"east" : __DIR__"fuhusi",
		"west" : __DIR__"jietuopo",
	]));

	set("outdoors", "shaolin");
	setup();
	replace_program(ROOM);
}



