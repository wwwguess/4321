inherit NPC;
 
void create()
{
        object ob;

        set_name("��С��", ({ "shao-de" }) );
        set("gender", "Ů��" );
        set("age",18);
        set("long", @TEXT
������ʮ��Ư���������̲�ס���������ۣ���������
���ŵ���������������������ò�������ͷ�����ŵ�
��������ӯ�Ĳ���������Ŷ!
��������ׯ����ֹƼ����Ů��ƽ��ׯ�ڵĽӴ��ǿ�����
TEXT
);
       set("class", "dancer");
       set("combat_exp", 60000);
       set("potential", 200);
        set("kee",350);
        set("san",100);
        set_skill("unarmed",60);
        set_skill("dodge", 50);
        set_skill("force",50);
       set("force", 2000);
       set("max_force", 2000);
       set("force_factor",2);
       set_temp("apply/armor", 50);
       create_family("����ׯ",3,"�����");

        setup();
        ob = carry_object(__DIR__"obj/needle");
        ob->set_amount(30);
        carry_object(__DIR__"obj/deer_boot")->wear();
        carry_object(__DIR__"obj/skirt3")->wear();
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
        switch( random(2) ) {
                case 0:
                  say( "С������΢Ц�����ƵĶ���˵��\n  ��λ" + 
RANK_D->query_respect(ob)
                   + "����ã���ӭ��������ׯ��������\n");
                        break;
                case 1:
                  say( "С������΢Ц����ϸ��˫�������裬\n ˵������λ" +
RANK_D->query_respect(ob)
                   + "����ã���ӭ��������ׯ�����ò裡\n");
        }
}
