// Room: /d/emei/basipan1.c ������ ��ʮ����1

inherit ROOM;

void create()
{
	set("short", "��ʮ����");
	set("long", @LONG
�������ٲ��Ϸ�һ��խխ��ɽ������Ȼ��ɡ�ʯ�������˹�
���һ�����ݡ����϶��˼���ľ׮�����ϴֳ���������Ϊ���֡�
�ٲ��ڽ��±��ڶ������ڲ�Զ��ɽ���»��һ����̶��
LONG
	);

	set("exits", ([
		"northdown" : __DIR__"leidongping",
		"east" : __DIR__"lengshanlin1",
		"southwest" : __DIR__"basipan2",
	]));

//	set("outdoors", "shaolin");
	setup();
	replace_program(ROOM);
}
