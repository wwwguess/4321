// Room: /d/road/jingdu.c

inherit ROOM;

void create()
{
	set("short", "��������վ");
	set("long", @LONG
�������˾����⡣��Զ�����Կ������ʵĳ�ǽ���Ͻ��ǵ����ܡ����ſ�
�ܶ����־����̲����ˡ�������͢�Խ����������ƺ��ϣ����ǲ�Ҫ������
���µ��ҵĺá�
    �������߾͵��˾�ʦ�����š���������ɽ����,���Ϸ��򵽱�����
������Ϸ����.
LONG
	);
	set("exits", ([ /* sizeof() == 5 */
		"southwest" : __DIR__"rdktojd4",
		"southeast" : __DIR__"rjdtodk0",
		"north" : "/d/city/sroad1",
//		"west" : __DIR__"rjdtoly0",
		"northeast" : __DIR__"rjdtoshg0",
]));

	setup();
	replace_program(ROOM);
}
