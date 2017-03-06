// Room: /d/city/jitan.c

inherit ROOM;

void create()
{
	set("short", "��̳");
	set("long", @LONG
����һƬ������С�㳡���㳡���м��ǻʼҵļ�̳(altar)��ÿ��
��͢��ף���ջ������ش������������У����ϡ��ʺ�������
�����ϼ�̳��������ֻ�ܴ��Ա��ƹ�ȥ�����˽������Ĺٱ��͹����
����ż�������⣬���������������������Ͻ��ǵ������ţ�������һ
���ǳ����ֵ�ʮ��·�ڡ�
LONG
	);
	set("exits", ([
		"south" : "/d/city/shenwumen",
		"north" : "/d/city/street7",
	]));
	set("item_desc", ([
		"altar": 
	"԰��̳���������ú��������ɵģ�̳���ɾ�ϸĥ���Ļ������̳ɣ���\n"
	"���и�̨��(platform)��\n",
		"platform": 
	"ֻ�лʵ���վ�����������̨�����棬��Լ������󿴵�̨�ӵ�����\n"
	"�и�͹��(sth)��\n",
		"sth": 
	"�����һ����ť(button)�����泤��ϸϸ����̦����ͻȻһ��Ī����\n"
	"��Ľ��ţ�������ȴ��ʹ�����������ť���㷢�������԰�(press)��\n"
	"Ҳ������ת(turn)��\n"
	]) );

	setup();
}

void init()
{
	add_action("do_turn", "turn");
	add_action("do_press", "press");
}

void close_passage()
{
	object room;

	if( !query("exits/down") ) return;
	message("vision", "�ذ��Ȼ����������������һ����滺���ƶ����������µ�ͨ����\ס�ˡ�\n",
		this_object() );
	if( room = find_object("/d/city/midao1") ) {
		room->delete("exits/up");
		message("vision", "�컨���Ȼ�������������������ϵĽ����ֻ��������˻�ȥ��\n",
			room );
	}
	delete("exits/down");
}

int do_turn(string arg)
{
	string dir;

	if( !arg || arg=="" ) return 0;

	if( arg=="button" ) {
		write("��ת��ת�����ť����˳ʱ�����ʱ�뷽����ת����\n");
		return 1;
	}
	if( sscanf(arg, "button %s", dir)==1 ) {
		if( dir=="forward" ) {
			message_vision("$N����ť��˳ʱ��ת��һȦ��ʲô����Ҳû������\n", this_player());
			add("forward", 1);
			return 1;
		} else if( dir=="backward" ) {
			message_vision("$N����ť����ʱ��ת��һȦ��ʲô����Ҳû������\n$N��Ȼ���˸���������������ﺦ���ˡ�\n", this_player());
			add("backward", 1);
			return 1;
		} else {
			write("��������˳ʱ��(forward)ת������ʱ��(backward)ת��\n");
			return 1;
		}
	}
}


int do_press(string arg)
{
	string dir;
	object room;

	if( !arg || arg=="" ) return 0;

	if( arg=="button" ){ //return 0;

	if( (int)query("forward")==1
	&&	(int)query("backward")==3
	&&	!query("exits/down") ) {
		message("vision", "�ذ��Ȼ����������������һ����滺���ƶ�����¶��һ�����µĽ��ݡ�\n",
			this_object() );
		set("exits/down", "/d/city/midao1");
		if( room = find_object("/d/city/midao1") ) {
			room->set("exits/up", __FILE__);
			message("vision", "�컨���Ȼ����������������¶��һ�����ϵĽ��ݡ�\n",
				room );
		}
		delete("forward");
		delete("backward");
		call_out("close_passage", 3);
	}
	return 1;}
}


void reset()
{
	::reset();
	delete("forward");
	delete("backward");
}
