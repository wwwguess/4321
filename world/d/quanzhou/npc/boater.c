// boater.c

inherit NPC;

void create()
{
        set_name("�ϴ���", ({ "boater" }) );
        set("gender", "����" );
        set("age", 58);
        set("shen_type", 0);

        set("long",
                "һλ������ɣ����������ϵ�����˵����һ�С�\n");
        set("combat_exp", 5000);
        set("attitude", "friendly");
        set_skill("unarmed", 100);
        
        set("inquiry", ([
                "�һ���" : "�һ������������������ˡ�\n"
                ])
           );

        setup();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
    add_action("do_boat","boat");
        
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
        case 0:
                say( "�ϴ���˵������λ" + RANK_D->query_respect(ob)
                        + "������(boat)��\n");
                break;
        case 1:
                say( "�ϴ������������˵:�⼸�쵽�һ���������ô��ô�ࣿ\n");
                break;
        }
}

int do_boat(string arg)
{
 if(arg!="�һ���"){
                   command("say ȥ���Ҳ��贬��");
                   return 1;
                   }
 command("say һ·���С�ġ�");
 message_vision("$N���ϴ��������һ��С����\n",this_player());
 this_player()->move("/d/taohua/boat.c");
 return 1;
}
