 int l, r, x;
            if (t == 1)
            {
                cin >> l >> r;
                cout << seg.RangeQuery(0, 0, n - 1, l, r) << endl;
            }
            else
            {
                cin >> l >> r >> x;
                seg.RangeUpdate(0, 0, n - 1, l, r, x);
            }