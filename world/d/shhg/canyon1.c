// ROOM:__DIR__"canyon1"

inherit ROOM;
void create()
{
        set("short","��ʯ����β");
	set("long",@LONG
����Ϊ��ʯ����·�������Ǹ������ƵĻ�ɽ���������������ޱ��޼�
�գ���ԵΪһɽ�ڣ�������һ����ʮ�ߡ����ɵ�����(chain) �������
�ž����˼���ν�ġ��������ޣ�ѩͤ�򡹡�
LONG
	); // eof(long)

	set("item_desc", ([
        	"chain" : @TEXT
    һ��������Եɽ�ڶ��ϣ����޾��ѵ������ͺò�Ҫ��������(climb)��
TEXT
	]) );
	
	set("exits",([ /* sizeof()==1 */
		"southwest" : __DIR__"canyon2",
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

        message_vision("$N�ֽŲ��ã�Ŭ������������������Ե��ȥ��\n",me);
                       
	me->receive_damage("gin", 30);
	me->receive_damage("kee", 40);
	me->receive_damage("sen", 20);
	
	if ( ((int)me->query("gin") < 0) ||
	     ((int)me->query("kee") < 0) ||
	     ((int)me->query("sen") < 0) ) {   //�б�ʽ
           	tell_room(__DIR__"road",me->name()+"������֧�ˡ�\n");
            	me->move(__DIR__"road");
	        return 1;
	}
        
        tell_room(__DIR__"road",me->name()+"ƽ���Ĵ���������������\n");
	me->move(__DIR__"road");
        return 1;
}

