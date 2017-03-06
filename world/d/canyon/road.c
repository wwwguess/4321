// ROOM:__DIR__"road"

inherit ROOM;
void create()
{
        set("short","��ʯС·");
	set("long",@LONG
����������ʯС·�ϣ������ľ�ɫ�����������������ϡ�٣�����
�˻��ߵ����������·β��һ��Բ�ε����ѣ�������һ��������������(
chain)�Ϳ���ͨ���ʯ���ڣ������������ν���ѩͤ�����ʯ�ٵ���
LONG
	); // eof(long)

	set("item_desc", ([
        	"chain" : @TEXT
    һ��������Եɽ�ڶ��£������������������(climb)��
TEXT
	]) );
	
	set("exits",([ /* sizeof()==1 */
		"northeast" : "/d/snow/sroad3",
	]) ); //eof(exits)
	
	setup();
	
} 

void init()
{
	add_action("do_climb", "climb");
}

int do_climb(string arg)
{ 
        object me;
        
        me=this_player();
        
	if ( arg != "chain" ) return 0;

        message_vision("$N�ֽŲ��ã�Ŭ����������������������ȥ��\n",me);
                       
	me->receive_damage("gin", 20);
	me->receive_damage("kee", 30);
	me->receive_damage("sen", 10);
	
	if ( ((int)me->query("gin") < 0) ||
	     ((int)me->query("kee") < 0) ||
	     ((int)me->query("sen") < 0) ) {   //�б�ʽ
           	tell_room(__DIR__"canyon1",me->name()+"������֧�ˡ�\n");
            	me->move(__DIR__"canyon1");
	        return 1;
	}
        
        tell_room(__DIR__"canyon1",me->name()+"ƽ���Ĵ���������������\n");
	me->move(__DIR__"canyon1");
        return 1;
}

