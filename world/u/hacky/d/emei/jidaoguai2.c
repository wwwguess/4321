// Room: /d/emei/jiudaoguai2.c ������ ��ʮ�ŵ���2

inherit ROOM;

void create()
{
	set("short", "��ʮ�ŵ���");
	set("long", @LONG
�������ٲ��Ϸ�һ��խխ��ɽ������Ȼ��ɡ�ʯ�������˹�
���һ�����ݡ����϶��˼���ľ׮�����ϴֳ���������Ϊ���֡�
�ٲ��ڽ��±��ڶ������ڲ�Զ��ɽ���»��һ����̶��
LONG
	);

	set("exits", ([
		"eastdown" : __DIR__"jiudaoguai1",
		"southwest" : __DIR__"jiudaoguai3",
	]));

	set("outdoors", "shaolin");
	setup();
	replace_program(ROOM);
}



