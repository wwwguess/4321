// drinkmonk2.c
inherit NPC;
int go_in();
void create()
{
    set_name("�������",({"drink monk","monk"}));
    set("long","����һ��ɮ��ɮ�ײ��ף���ͷ�ҷ��Ĺ���\n");
    set("gender","����");
    set("age",42);
    set("int",20);
    set("cor",30);
    set("cps",20);
    set("gin",500);
    set("max_gin",500);
    set("eff_gin",500);
    set("max_kee",500);
    set("eff_kee",500);
    set("kee",500);  
    set("max_sen",500);
    set("sen",500);    
    set("eff_sen",500);
    set("combat_exp",1000000);
    set_skill("force",100);
    set_skill("lotusforce",100);
    set_skill("unarmed",100);
    set_skill("parry",50);
    set_skill("dodge",50);
    set("force",1000);
    set("max_force",1000);
    set("force_factor",100);
    map_skill("force","lotusforce");
    set("attitude", "heroism");
    setup();
    carry_object(__DIR__"obj/cloth")->wear();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

int greeting(object me)
{
 
    if( !me || environment(me) != environment() ) return 1;
    say ("�������˵���������˷��ӽ���ȥ�����Ӿ�Ҫ�Ǵ��ˡ������������ҲҪץ����������\n");
    say ("������л������ˣ����ѷ�������ص���\n");
    destruct( this_object());
    return 1;
}