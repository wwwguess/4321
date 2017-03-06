// Room: /d/canyon/bamboo/train.c

inherit ROOM;

void create()
{
	set("short", "����ʯ��");
	set("long", @LONG
�쬵ķ粻ͣ����������Ϯ�������ʯ�ҵ����ܾ����ĸ��󶴸�
�ֲ����������ķ���������ȥ����һ�������֣���֮ǰ������ֻ
�����ڷ��ƵĴ�С��ǿ��������ͻ�ͦ�������ӣ���������ҡ�εĵ�
����������һ�������Ƹ�֮ͼ��������һʯ�����(bookcase)����ɢ
����������⣬��֮ǰ����֮����һ��������ϻ������һ�������
����������Դ��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"out" : __DIR__"bamboo3",
]));

        set("item_desc", ([
        "bookcase" : "�������Ǹ�����ͨͨ�Ĺ��ӣ�����\�����search������\n",
	]) );

	setup();
}

void init()
{
	add_action("search_case","search");
}

int search_case(string arg)
{
	object me,obj;
	
	if ( !arg || (arg!="bookcase") ) return 0;
	
	me=this_player();
	if ( query_temp("got") ) {
		message_vision("$N����������ҵ�û�ҵ�Щʲô\n",me); 
		return 1;
	}
	
	message_vision("$N����������˵�һ����ϻ\n",me);
	obj=new(__DIR__"obj/slipcase");
	obj->move(me);
	set_temp("got", 1);
	return 1;
}	
	
