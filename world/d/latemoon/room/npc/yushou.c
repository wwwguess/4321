inherit NPC;
 
void create()
{
         set_name("������", ({ "yushou","yu","shou" }) );
        set("gender", "Ů��" );
        set("age",18);
        set("long", @TEXT
�����������л����������������񡣸���
һ�ֽ���������ü�����ƣ�������֮����
��������Ů�����еĽ��ᡣ
TEXT
);
       set("class", "dancer");
       set("combat_exp", 15000);
        set_skill("unarmed",40);
        set_skill("dodge", 40);
        set_skill("stormdance", 50);
        set_skill("tenderzhi", 60);
        set_skill("force",50);
        map_skill("dodge","stormdance");
        map_skill("unarmed","tenderzhi");
        set("force", 400);
        set("max_force", 400);
        set_temp("apply/armor", 100);

       create_family("����ׯ",3,"����");
        setup();
        carry_object(__DIR__"obj/earring")->wear();
        carry_object(__DIR__"obj/brooch")->wear();
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

void greeting(object ob)
{
        if( !ob || !present(ob, environment(this_object())) ) return;
        command("close door");
        say ("����! ������ׯ�ں����᷿���������пͽ���Ŷ! \n" +
              "�����ֹ��ţ������ְ���! лл! \n" );
}
