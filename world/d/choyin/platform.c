inherit ROOM;

void create()
{
        set("short", "��̨");
        set("long", @LONG
����֮�ۣ����ƶ�䣬���ǧ���������֮ɽ�������˾��ɣ���������ѩ����Լ�紦��..
�������٣�ֻ�������Ȼ���ƿ�֮����͹��һ����̨(platform)
LONG
        );
        set("item_desc", ([
                "platform":
                    "һ������ϸ������̨,����һ����;����������ƿ,���꺮������
��������.̨����һ���(flag),�����ɼұ���.\n",
                "flag":"��ᦿɷ��Ƹ���,��ò�Ҫ��(touch)��.\n",
          ]) );      
        set("objects", ([
                __DIR__"npc/lboy" :2,
        ]) );

        setup();
        
} 


void init()
{     
        add_action("do_touch", "touch");
}


int thounder(object ob)

{
        int i;
        int damage;
        if( environment(ob) == this_object())
        {
        message_vision("ɲ�Ǽ�ͮ���ܲ�,ɽ����ɫ.������������$N...\n", ob);
        message_vision("$N��ʱ�������,����ð��...\n", ob);
        tell_room("/d/choyin/platform","���ŵ�һ���ս���ζ��.\n");                                                                         
        i = (int)ob->query("eff_kee");
        damage = random(10)+35  ;
        ob->set("eff_kee",(int) i - damage );
        i =  (int)ob->query("kee");
        ob->set("kee",(int) i - damage);
        if( environment(ob) == this_object())
        call_out("thounder",5, ob);
        }
        else

        return 1;
}


void close_passage()
{
        if( !query("exits/down") ) return;
 message("vision", "һ���������,��̨��£��.\n",
                        this_object() );                      
        delete("exits/down");
}


int do_touch(string arg) 
{
       string dir;
       object ob;
       if( !arg || arg=="" ) return 0;

       if( arg=="flag" ) {
                write("���������,��ᦶ���һ��.....\n");
        if( interactive(( ob = this_player())) )
        remove_call_out("thounder");
        call_out("thounder", 15, ob);            
        message("vision", "�׹�һ��,��̨�����ѿ�\n",
                        this_object() );                       
        set("exits/down", __DIR__"stove");
        call_out("close_passage", 1);  
        return 1;
        }
}


