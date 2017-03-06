#include <ansi.h>
#define BASE_MONEY 300

inherit ROOM;

string *make_msg = ({
    HIG "���򳤱�һ˦, �����˴��.\n\n" NOR,
    HIG "��Խ��Խ��.\n\n" NOR,
    HIG "��Խ��Խ��.\n\n" NOR,
    HIG "��Խ��Խ��.\n\n" NOR,
    HIG "��Խ��Խ��.\n\n" NOR,
    HIG "�����ڴ���Ϸɳ�, ���ڳ��ϻ����˯.\n\n" NOR,
    HIG "����˵: �쵽��, ��һ��!\n\n" NOR,
});

mapping yizhan=([
		"����"   : "/d/guanwai/yizhan",
		"��ʦ��" : "/d/city/wyizhan",
	                  ]);

mapping time=([
		"����" : 6,
		"��ʦ��" : 12,
	                  ]);
                          
void create()
{
	set("short","��������վ");
	set("long", @LONG
    �����Ǳ��ص���վ����Ǯ�˿��Դ�����ͳ�ȥ����ء�ǽ����һ������(paizi). 
����һ�����ϰ������Աߵ����⡣
LONG
	);

	set("exits", ([
                "south" :"/d/road/jiayuguan",
	]));
	
	
       // set("objects",([
       //        
         //d/yueyang/npc/chefu" : 1,
//

	
	setup();
}

void init()
{       

        add_action("do_qu", "qu");
	add_action("do_look","l");
	add_action("do_look","look");

}

 
int do_qu(string arg)
{
        object who,che;
	string *zhan;
	int i,flag=0;
	         
        who=this_player();

	zhan=keys(yizhan);
	i=sizeof(zhan);
	while(i--)
	{
		if(arg==zhan[i])
		{
			flag=1;
			break;
		}
	}
	if(flag==0)  return notify_fail(YEL"��ȥ����ط�\n"NOR);

	if ( !(che=find_object(__DIR__"che"))) che=clone_object(__DIR__"che");
	if (che->query("youren"))	
	{
		return notify_fail("���Ѿ���ȥ��,���һ�����\n");
	}

	switch (MONEY_D->player_pay(who, BASE_MONEY*time[arg]) )
	{
	case 0:
		return notify_fail("������ĵض���˵��������⵰��һ�ߴ���ȥ����\n");
	case 2:
		return notify_fail("������Ц������������Ǯ�����ˣ���Ʊ��û���ҵÿ�����\n");
	default:
		tell_object(who, "����Ц���е�˵��:�����Ϊ��׼������\n");
	}

	message_vision(HIR "�������һ��������$N�ĸ�ǰ,˵��:���ϳ�!!\n" NOR,who);
 	who->move(__DIR__"che");
	che->set("youren",1);
	tell_object(who, make_msg[0]);
       	remove_call_out("gozhan");
	call_out( "gozhan", time[arg], who, 1, arg,che);

       	return 1;

}

int gozhan(object who, int stage,string arg,object che)
{
	int len;

	len=sizeof(make_msg);

	tell_object(who, make_msg[stage]);
	if( ++stage < len )
	{
		call_out( "gozhan", time[arg], who, stage ,arg,che);
	        return 0;
	} 

	tell_object(who,HIG "��վ��!\n" NOR);
        if (who->move(yizhan[arg]))
	{
		che->delete("youren");
		return 1;
}	

	who->move(VOID_OB);
	return notify_fail("�������κ����������һ��İ���ĵط���\n");
}               

int do_look(string arg)
{
	string *zhan,str;
	object who;
	int i;

	if(arg=="paizi")
	{
		zhan=keys(yizhan);
		who=this_player();
		i=sizeof(zhan);

		tell_object(who,"���г�ֱ��(qu)ȫ�����µط�:\n\n");
		while(i--)
		{
			str=sprintf("%12s   ������:%4d��\n",zhan[i],time[zhan[i]]*BASE_MONEY/100);
			tell_object(who,str);
		}
		return 1;
	}

	return 0;
}
