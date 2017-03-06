// Room: /d/village/lakebottom2.c

inherit ROOM;

void create()
{
	set("short", "ˮ���Ҷ�");
	set("long", @LONG
ˮ���Ҷ��������ͻȻ��÷ǳ��������޴��񷶥�ɰ�͸������ģ
���ؿ��������С��������ȥ�����϶��µĿ�ȥ���㲻������һ��������
��ֻ��ɫ�Ĵ����������ڿ��С������ڱ����ϡ��������ڶ����ˮ̶�С�
������һ���ƵĽ����������ϣ���֪�������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "westup" : __DIR__"valley1",
  "eastdown" : __DIR__"lakebottom1",
]));
	set("objects", ([
		__DIR__"npc/dragon":6, 
	]) );
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
