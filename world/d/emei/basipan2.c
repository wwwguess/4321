// Room: /d/emei/basipan2.c ������ ��ʮ����2

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
		"northeast" : __DIR__"basipan1",
		"southeast" : __DIR__"lengshanlin1",
		"southup" : __DIR__"basipan3",
	]));

//	set("outdoors", "shaolin");
	setup();
	replace_program(ROOM);
}