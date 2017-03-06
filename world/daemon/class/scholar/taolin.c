// Room: /daemon/class/scholar/taolin

inherit ROOM;
/*
#define dir_east	0
#define dir_south	1
#define dir_west	2
#define dir_north	3
#define dir_southeast	4
#define dir_southwest	5
#define dir_northeast	6
#define dir_northwest	7
*/
string Get_Dir(string arg);
int do_read(string arg);
int do_go (string arg);

mapping Note_Msg = ([
        "�������ĸ�����,���ֱ��ҹ��--":"dir_west",
        "�ʾ����м����,ǡ��һ����ˮ��--��":"dir_east",
        "��Ц���ú�ʹ,���������ˮ,����ֻ��--":"dir_east",
        "--���İٰ�ʮ��,����¥̨������":"dir_south",
        "��ȸ--��,����һ�ǻ�":"dir_southeast",
        "����--��,�˱Ȼƻ���":"dir_west",
        "���--¥�Ѳ���,��������,��ɢ������":"dir_west",
        "������ɫ,��ˮ�̲�,�;�--��,��֮���":"dir_south",
        "--����������":"dir_northwest",
        "--���ذײ��ۣ�������¼���ѩ":"dir_north",
        "��ɽ��--������ˮ�ƶ���":"dir_north",
        ]);


string	*notemsg;
int 	msg_no;
// int tl_steps;
 
void create()
{
        set("short", "����");
        set("long", @LONG
���Ǻܴ��һƬ���֡�ÿ�껨���ļ��ڣ�����һƬ�һ����ã�������
�ڽ����򼯵��ο����ۿ����������ǵ��ο�Ҳ�������ˡ���������İ�ݺ�
������Ϥ�˵ص��ο;�����·����Ȼ����һЩ������������֦�Ϲ���Щ��
����ָʾ��·��������������note�����Ƕ�����
LONG
        );

        set("item_desc", ([
                "note": (: "����һ��ָʾ·��������.�ƺ����Զ�(read)��.\n" :),
        ]) );

        set("exits", ([ 
                "south" : 	__DIR__"taolin",
                "north" : 	__DIR__"taolin",
                "west" : 	__DIR__"taolin",
                "east" : 	__DIR__"taolin",
		"northwest":	__DIR__"taolin",
//		"northeast":	__DIR__"taolin",
		"southeast":	__DIR__"taolin",
//		"southwest":	__DIR__"taolin",
        ]));

	notemsg = keys(Note_Msg);
	msg_no = random(sizeof(Note_Msg));	
//        tl_steps = this_player()->query("taolin_steps");

	setup();
}

void init()
{
	add_action("do_read", "read");
	add_action("do_go", "go");
}

int do_read(string arg)
{
	if (arg != "note") 
		return notify_fail("��Ҫ��ʲô?\n");
	    else {
		message_vision("$N����:"+notemsg[msg_no]+"\n", this_player()); 
		return (1);
		}
}

int do_go(string dir)
{
	int steps;
	object me;

	me = this_player();
	steps = me->query("taolin_steps");
	if (dir == Get_Dir(Note_Msg[notemsg[msg_no]])) {
		if (steps  <= 1) {
			me->delete("taolin_steps");
			message_vision("$N�߳�������\n",me);
			me->set("marks/����", 1);
                        msg_no = random(sizeof(Note_Msg));
			me->move(__DIR__"entrance");
			message("vision",me->name()+"���������˳�����\n",environment(me),({me}));
			return 1;
			}
		    else {
			steps -= 1;  
			me->set("taolin_steps", steps);
			}
		}
	    else {
		steps += 3;
		me->set("taolin_steps", steps);
		}
	
	msg_no = random(sizeof(Note_Msg));
	return 0;
}

string Get_Dir(string arg)
{
	switch (arg) {
		case "dir_east":	return ("east");
		case "dir_south":	return ("south");
		case "dir_west":	return ("west");
		case "dir_north":	return ("north");
		case "dir_southeast":	return ("southeast");
		case "dir_southwest":	return ("southwest");
		case "dir_northeast":	return ("northeast");
		case "dir_northwest":	return ("northwest");
		default:	return ("NULL");
	}

}
