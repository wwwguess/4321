// Room: /d/green/house3.c

inherit ROOM;

int num_of_spider;

string call_spider();

void create()
{
	set("short", "��լ");
	set("long", @LONG
����һ����լ, ���ڳ���һ��ʯ��������һ������. �谵����
�ڿ�������������, �ƺ������ӵ����˺ܾ�û������. �ݽ���һ��
��״����ֵ�֩����(web).
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "south" : "/d/green/field1",
]));
	set("no_clean_up", 0);
	set("item_desc", ([
	"web" : (: call_spider :),
	]) );

	setup();
	reset();
}

void reset()
{
	::reset();
	num_of_spider = 3;
}

string call_spider()
{
	object ob;
	if (num_of_spider == 0) return "һ���ܴ��֩����.\n";
	num_of_spider --;
	ob = new("/d/green/npc/spider");
	ob->move("/d/green/house3");
	return "ͻȻ�����ͷ���и���Ӱ, ���Ծ���̧��ͷ��һ�� ............"+
	"�ô�� ..... ֩��..... \n";
}
