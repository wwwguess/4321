// Mon  08-21-95

inherit ROOM;

string call_spider();

int num_of_spider;

void create()
{
	set("short", "��լ");
	set("long", @LONG
����һ����լ, ���ڳ���һ��ʯ��������һ������. �谵����
�ڿ�������������, �ƺ������ӵ����˺ܾ�û������. �ݽ���һ��
��״����ֵ�֩����(web).

LONG
	);
    set("exits", ([
    "south" : __DIR__"field1",
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
    if (num_of_spider == 0) return "һ�źܴ��֩����.\n";
	num_of_spider --;
    ob = new(__DIR__"npc/spider");
    ob->move(__DIR__"house3");
	return "ͻȻ�����ͷ���и���Ӱ, ���Ծ���̧��ͷ��һ�� ............"+
	"�ô�� ..... ֩��..... \n";
}
