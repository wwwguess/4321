
inherit ROOM;

void create()
{
	set("short", "�����ȹȿ�");
	set("long", @LONG
���������ȹȿڣ�ǰ����һ���ߴ���ͱڣ�������ɼ�һ���������ڵ���ȣ�
����Զ����ɽ������һ�ֲ����Ԥ�С�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  	"west" : "/d/yulan/xiaolu",
 	"northdown" : "/d/moon/road",
]));
	setup();
	replace_program(ROOM);
}
