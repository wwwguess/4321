// xiangcha.c ���
// By Marz 03/29/96

inherit ITEM;

void init();
void do_eat();

void create()
{
	set_name("���",({"tea", "cha", "xiang cha"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ���Ȳ裬���Ƶ�ð������������\n");
		set("unit", "��");
		set("value", 1000);
        set("remaining", 2);
        set("drink_supply", 25);
    }
	
	setup();
}

void init()
{
	add_action("do_drink", "drink");
}


int do_drink(string arg)
{

	int heal, recover, sen, e_sen, m_sen;
	
	recover = 5;
	
    if( !this_object()->id(arg) ) return 0;
    if( this_player()->is_busy() )
        return notify_fail("����һ��������û����ɡ�\n");
    if(   (int)this_player()->query("water")
       >= (int)this_player()->max_water_capacity() )
     return notify_fail("���Ѿ���̫���ˣ���Ҳ�಻��һ��ˮ�ˡ�\n");

	set("value", 0);
    this_player()->add("water", (int)query("drink_supply"));
    sen = (int)this_player()->query("sen");
    e_sen = (int)this_player()->query("eff_sen");
    m_sen = (int)this_player()->query("max_sen");

// No heal effect for ���
/***

    if ( e_sen < m_sen )
	{ 	
		if ( (e_sen + heal) >= m_sen )
		{
			this_player()->set("eff_sen", m_sen);
		} else
		{	
			this_player()->set("eff_sen", e_sen+heal);
		}	
	} 
***/

	if (sen < e_sen )
	{
        if ( (sen + recover) >= e_sen )
        {
            this_player()->set("sen", e_sen);
        } else
        {   
            this_player()->set("sen", sen+recover);
        }   
	}

    if( this_player()->is_fighting() ) this_player()->start_busy(2);

    add("remaining", -1);
	if ( query("remaining") )
	{
   		 message_vision("$N������裬������ζ��Ʒ�˼��ڡ�\n"+
      		"һ������ֱ����Ƣ��$N���þ���ö��ˡ�\n", this_player());
	} else 
	{ 
   		 message_vision("$N�����С������ʣ�µ����һ��������\n"+
      		"һ������ֱ����Ƣ��$N���þ���ö��ˡ�\n", this_player());
		
		destruct(this_object());
	}

	return 1;
}
