// Room: /d/emei/jiudaoguai3.c ������ ��ʮ�ŵ���3

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
		"northeast" : __DIR__"jiudaoguai2",
		"westup" : __DIR__"jiudaoguai4",
	]));

	set("outdoors", "shaolin");
	setup();
	replace_program(ROOM);
}



