// chuchang shi

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������ؤ��Ĵ����ң�������ֻ�ܿ���һ�������ŵ����ӡ�
LONG
	);
	set("exits", ([
		"west" : __DIR__"mishi",
		"up" : __DIR__"undertre",
	]));
set("objects",([
       "/class/gaibang/huo-du.c":1
               ]));

	setup();
	replace_program(ROOM);
}
