// Room: /d/village/lordhouse3.c

inherit ROOM;
string look_shield();

void create()
{
	set("short", "�������Ϸ�");
	set("long", @LONG
�Ϸ����õ�����鷿�������ӵ��м���һ�Ŵ��������������ǽ����
��һ�����(shield)������ܰ��˼����顣���Ϻ�������������󴰻���
������ȥ����ģģ��������������������¥���������Կ��������æµ
����ũ��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"lordhouse1",
]));
	set("item_desc",([
	//	"shield": "������Ϻ�����Ű˱��飬����Խ������е�ĳһ����(take)������\n�򽫳��������Ż�ȥ(putback)��\n",
		"shield": look_shield(),
	]) );
	
	set("no_clean_up", 0);

	setup();
//	replace_program(ROOM);
}

void init()
{
	add_action("do_takeout","take_out");
	add_action("do_push","push");
}

int do_takeout(string arg)
{
	object room;
	string num;
	
	if( !arg || arg=="" )
		return notify_fail("��Ҫ��ʲô��\n");
	if( arg=="book" ) {
	write("�����õڼ���ʯ�飿\n");
	return 1;
	}
	
	if( sscanf(arg, "book %s", num)==1 ) {
	    if( num <"0" || num >"12" ){
	    	return notify_fail("�ж��ٱ��飬����ϸ������ˣ�\n");
	    }
	    switch( num ){
	    	case "9":
		    if( (int)query("key")==0 )
		    	add("key",1);
		    else
		    	add("key",6);
		    break;
	    	case "3":
		    if( (int)query("key")==1 )
			add("key",1);
		    else
			add("key",6);
		    break;
		case "11":
		    if( (int)query("key")==2 )
			add("key",1);
		    else
			add("key",6);
		    break;
		case "6":
		    break;
//		    if( (int)query("key")==3 ){
//		    	if( room = find_object("/d/village/lordhouse2") )
		   
//		    }
	    }
	}

	return 1;
}

string look_shield()
{
//	string book[16];
	int iCount;
	return "are this true?\n";
}
